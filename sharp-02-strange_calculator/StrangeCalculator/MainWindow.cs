using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace StrangeCalculator
{
    public partial class MainWindow : Form
    {
        Dictionary<string, Variable> vars;
        Calculator calculator;
        public MainWindow()
        {
            InitializeComponent();
            textBoxX.TextChanged += (o, e) => VariableValueChanged("x", textBoxX.Text);
            textBoxY.TextChanged += (o, e) => VariableValueChanged("y", textBoxY.Text);
            textBoxZ.TextChanged += (o, e) => VariableValueChanged("z", textBoxZ.Text);
            vars = new Dictionary<string, Variable> {
                { "x", new Variable() }, { "y", new Variable() }, { "z", new Variable() }
            };
            calculator = new Calculator();
            calculator.OnValueChanged += UpdateResponse;
        }

        private void UpdateResponse(double result)
        {
            if (textBoxBeta.InvokeRequired){
                textBoxBeta.Invoke(new MethodInvoker(delegate { textBoxBeta.Text = result.ToString(); }));
            }
        }

        /// <summary>
        /// Обработчик событий обновления введённого текста в TextBox подцепляет введённое число и, если удаётся его привести к дублю, обновляет Value.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void VariableValueChanged(string var, string new_value)
        {
            double res;
            vars[var].IsChanged = true;
            if (!double.TryParse(new_value, out res)) {
                vars[var].IsGood = false;
                return;
            }
            vars[var].IsGood = true;
            vars[var].Value = res;
            Task.Run(() => UpdateVariables());
        }

        private void UpdateVariables() {
            bool canUpdateCalculatorState = true;
            foreach (KeyValuePair<string, Variable> kv in vars) {
                canUpdateCalculatorState &= kv.Value.IsGood;
            }
            if (!canUpdateCalculatorState) {
                return;
            }
            foreach (KeyValuePair<string, Variable> kv in vars) {
                if (kv.Value.IsChanged) {
                    calculator.ChangeVariable(kv.Key, kv.Value.Value);
                    kv.Value.IsChanged = false;
                }
            }
        }
    }
}
