using System;
// ��������� ����� ������ ��������� � �������� � �������� � ����� ������
class Program {
	static void Main(string[] args) {
		Console.Write("������ �������: ");
		
		if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0) {
			Console.WriteLine("������: ������ ������ ���� ����������� ������");
			return;
		}
		
		int[,] array = new int[n, n];
		int[] sum = new int[n];
		Console.WriteLine("�������� ������� ���������:");

		for (int i = 0; i < n; ++i) {
			Console.Write($"������ {i + 1}: ");
			string[] input = Console.ReadLine().Split(' ');

			if (input.Length != n) {
				Console.WriteLine($"������: � ������ ������ ���� {n} ���������.");
				--i;
				continue;
			}

			for (int j = 0; j < n; j++) {
				if (!int.TryParse(input[j], out array[i, j])) {
					Console.WriteLine($"������: '{input[j]}' - �� �����.");
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

		Console.WriteLine("\n����� ������:");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				Console.Write(array[i, j] + "\t");
			}
			Console.Write("\r\n");
		}
	}
}