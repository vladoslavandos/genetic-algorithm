#include "knapsack_vector_generator.h"

// Объект, необходимый для случайной генерации числел
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Функция вывода вектора в удобном формате 
template<typename T>
ostream& operator<<(std::ostream& out, const vector<T>& obj) {
  out << '[';
  for (int i = 0; i < obj.size(); i++) {
    out << obj[i];
    if (i + 1 != obj.size()) 
      out << ", ";
  }
  out << ']' << endl;
  return out;
}

// Непосредственно функция генерации рюкзачного вектора
vector<int> generate_knapsack_vector(int i) {
  vector<int> res(SIZE);
  for (int& v: res)
    v = rng() % MAX[i] + 1;
  return res;
}

int main() {
  freopen("../gen_alg/lab/vectors_and_max_values.txt", "w", stdout);
  vector<int> max_vals_of_knapsack_vectors;

  // Вывод списка векторов и максимальных значений
  for (int i = 0; i < NUMBER_OF_VECTORS; i++) {
    auto vec = generate_knapsack_vector(i);
    max_vals_of_knapsack_vectors.push_back(*max_element(vec.begin(), vec.end()));
    cout << vec;
  }
  cout << endl << endl;
  for (int val: MAX)
    cout << val << endl;
  return 0;
}
