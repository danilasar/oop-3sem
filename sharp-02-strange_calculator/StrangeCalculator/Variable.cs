using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StrangeCalculator
{
    /// <summary>
    /// Переменная из математической формулы из задания позволяет отслеживать события ввода в реальном времени
    /// </summary>
    class Variable
    {
        public double Value;
        public bool IsGood;
        public bool IsChanged;
        public Variable(double value)
        {
            Value = value;
            IsChanged = IsGood = false;
        }
        public Variable() : this(0) { }
    }
}
