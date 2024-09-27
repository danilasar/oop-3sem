using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StrangeCalculator
{
    class Calculator
    {
        double varX, varY, varZ, result;
        public delegate void ErrorHandler(string s);
        public delegate void ValueHandler(double result);
        public ErrorHandler OnError;
        public ValueHandler OnValueChanged;
        public Calculator()
        {
            varX = varY = varZ = 0;
            Task.Run(() => Recalculate());
        }
        public void ChangeVariable(string var, double val)
        {
            switch(var)
            {
                case "x":
                    varX = val;
                    break;
                case "y":
                    varY = val;
                    break;
                case "z":
                    varZ = val;
                    break;
                default:
                    string message = "Некорректное имя переменной " + var;
                    OnError?.Invoke(message);
                    throw new MissingMemberException(message);
            }
            Task.Run(() => Recalculate());
        }
        public void Recalculate()
        {
            result = varX + varY + varZ;
            OnValueChanged?.Invoke(result);
        }
    }
}
