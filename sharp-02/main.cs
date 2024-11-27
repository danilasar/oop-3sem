using System;
// Посчитать сумму чётных элементов в столбцах и записать в новый массив
class Program {
	static void Main(string[] args) {
		Console.Write("Размер массива: ");
		
		if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0) {
			Console.WriteLine("Ошибка: размер должен быть натуральным числом");
			return;
		}
		
		int[,] array = new int[n, n];
		int[] sum = new int[n];
		Console.WriteLine("Элементы массива построчно:");

		for (int i = 0; i < n; ++i) {
			Console.Write($"Строка {i + 1}: ");
			string[] input = Console.ReadLine().Split(' ');

			if (input.Length != n) {
				Console.WriteLine($"Ошибка: В строке должно быть {n} элементов.");
				--i;
				continue;
			}

			for (int j = 0; j < n; j++) {
				if (!int.TryParse(input[j], out array[i, j])) {
					Console.WriteLine($"Ошибка: '{input[j]}' - не число.");
					--i;
					break;
				}
			}
		}

		for(int j = 0; j < n; ++j) {
			for(int i = 0; i < n; ++i) {
				if(array[i, j] % 2 == 0) {
					sum += array[i, j];
				}
			}
		}

		Console.WriteLine("\nНовый массив:");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Console.Write(array[i, j] + "\t");
			}
			Console.Write("\r\n");
		}
	}
}