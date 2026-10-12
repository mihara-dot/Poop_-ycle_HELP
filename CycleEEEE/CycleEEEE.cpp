/******************************************
 * Автор:    Рычков Михаил                *
 * Название: Циклы с пред- и постусловием *
 *           и постусловием               *
 * Вариант:  27                           *
 ******************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double heatFlow, liquidTemperature, ambientTemperature, innerDiameter, outerDiameter, coefficientThermalConductivity, coefficientHeatDissipation, pipeLength;
  const double pi = 3.14159;
  double firstStartDiameter = 0.091;
  double firstEndDiameter = 0.095;
  double firstStep = 0.001;
  double secondStartDiameter = 0.110;
  double secondEndDiameter = 0.155;
  double secondStep = 0.015;
  int diameterIndex;

  cout << "liquidTemperature = ";
  cin >> liquidTemperature;

  cout << "ambientTemperature = ";
  cin >> ambientTemperature;

  cout << "innerDiameter = ";
  cin >> innerDiameter;

  cout << "coefficientThermalConductivity = ";
  cin >> coefficientThermalConductivity;

  cout << "coefficientHeatDissipation = ";
  cin >> coefficientHeatDissipation;

  cout << "pipeLength = ";
  cin >> pipeLength;

  innerDiameter = innerDiameter / 100.0;

  diameterIndex = 0;

  do {
    outerDiameter = firstStartDiameter + diameterIndex * firstStep;

    heatFlow = (pi * pipeLength * (liquidTemperature - ambientTemperature)) / (1.0 / (2.0 * coefficientThermalConductivity) * log(outerDiameter / innerDiameter) + 1.0 / (coefficientHeatDissipation * outerDiameter));

    cout << "d0 = " << outerDiameter << " m, "
         << "Q = " << heatFlow << endl;

    diameterIndex++;
  } while (outerDiameter <= firstEndDiameter);

  diameterIndex = 0;

  while (secondStartDiameter + diameterIndex * secondStep <= secondEndDiameter) {
    outerDiameter = secondStartDiameter + diameterIndex * secondStep;

    heatFlow = (pi * pipeLength * (liquidTemperature - ambientTemperature)) / (1.0 / (2.0 * coefficientThermalConductivity) * log(outerDiameter / innerDiameter) + 1.0 / (coefficientHeatDissipation * outerDiameter));

    cout << "d0 = " << outerDiameter << " m, "
         << "Q = " << heatFlow << endl;

    diameterIndex++;
  }

  return 0;
}