using System;

class algoritmos
{
  static void Main()
  {
    int[] arr = new int[] {1, 2, 3, 4, 5};
    int mayor = MasGrande(arr);
    Console.WriteLine("El numero mayor es: " + mayor);
  }

  static int MasGrande(int[] arr)
  {
    int mayor = arr[0];
    foreach (int num in arr)
    {
      if (num > mayor)
      {
        mayor = num;
      }
    }
    return mayor;
  }
}
