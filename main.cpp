#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main()
{
  std::random_device r;
  std::fstream archivo("numeros.txt", std::ios::out);
  int n;

  cout << "Numero de datos : ";
  cin >> n;

  // Generar los n numeros
  for (int i = 0; i < n; ++i) {
    archivo << 1 + r() % 100 << '\n';
  }

  archivo.close();
  //---- ahora leemos datos del archivo numeros.txt y formamos dos archivos:
  //---- pares.txt e impares.txt

  fstream archivoFuente("numeros.txt", std::ios::in);
  fstream adePares("pares.txt", ios::out);
  fstream adeImpares("impares.txt", ios::out);

  int numero;

  while(archivoFuente >> numero)
  {
    if(numero%2==0)
      adePares << numero << "\n";
    else
      adeImpares << numero<<"\n";
  }

  archivoFuente.close();
  adePares.close();
  adeImpares.close();

  return 0;
}
