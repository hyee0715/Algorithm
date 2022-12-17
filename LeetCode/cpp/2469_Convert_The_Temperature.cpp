class Solution {
public:
	vector<double> convertTemperature(double celsius) {
		vector<double> answer;

		double kelvin = celsius + 273.15;
		double fahrenheit = celsius * 1.80 + 32.00;

		answer.push_back(kelvin);
		answer.push_back(fahrenheit);

		return answer;
	}
};