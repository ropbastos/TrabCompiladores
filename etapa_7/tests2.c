int main() {
  int divisivel;
  int repeticoes;
  int i;

  repeticoes = 61;
  divisivel = 2;

  for (i = 0: i < repeticoes: i = i + 1)
  {
    divisivel = divisivel * 2;
  }

  for (i = 0: i < repeticoes: i = i + 1)
  {
    divisivel = divisivel / 2;
  }

  return divisivel;
}

