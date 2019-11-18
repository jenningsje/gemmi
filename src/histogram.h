// Copyright 2017 Global Phasing Ltd.

#include <cstdio>
#include <vector>

#define USE_UNICODE
#ifdef USE_UNICODE
# include <clocale>  // for setlocale
# include <cwchar>   // for wint_t
#endif

template<typename T>
void print_histogram(const std::vector<T>& data, double min, double max) {
#ifdef USE_UNICODE
  std::setlocale(LC_ALL, "");
  constexpr int rows = 12;
#else
  constexpr int rows = 24;
#endif
  const int cols = 80; // TODO: use $COLUMNS
  std::vector<int> bins(cols+1, 0);
  double delta = max - min;
  for (T d : data) {
    int n = (int) std::floor((d - min) * (cols / delta));
    bins[n >= 0 ? (n < cols ? n : cols - 1) : 0]++;
  }
  double max_h = *std::max_element(std::begin(bins), std::end(bins));
  for (int i = rows; i > 0; --i) {
    for (int j = 0; j < cols; ++j) {
      double h = bins[j] / max_h * rows;
#ifdef USE_UNICODE
      std::wint_t c = ' ';
      if (h > i) {
        c = 0x2588; // 0x2581 = one eighth block, ..., 0x2588 = full block
      } else if (h > i - 1) {
        c = 0x2581 + static_cast<int>((h - (i - 1)) * 7);
      }
      std::printf("%lc", c);
#else
      std::putchar(h > i + 0.5 ? '#' : ' ');
#endif
    }
    std::putchar('\n');
  }
}

