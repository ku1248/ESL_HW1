#include <cmath>

#include "GaussianFilter.h"

GaussianFilter::GaussianFilter(sc_module_name n) : sc_module(n) {
  SC_THREAD(do_filter);
  sensitive << i_clk.pos();
  dont_initialize();
  reset_signal_is(i_rst, false);
}

const int mask[MASK_X][MASK_Y] = {{1, 2, 1}, {2, 4, 2}, {1, 2, 1}};

void GaussianFilter::do_filter() {
  while (true) {
    val_r = 0;
    val_g = 0;
    val_b = 0;
    for (unsigned int v = 0; v < MASK_Y; ++v) {
      for (unsigned int u = 0; u < MASK_X; ++u) {
        val_r += i_r.read() * mask[u][v];
        val_g += i_g.read() * mask[u][v];
        val_b += i_b.read() * mask[u][v];
      }
    }
    val_r /= 16;
    val_g /= 16;
    val_b /= 16;
    o_result_r.write(val_r);
    o_result_g.write(val_g);
    o_result_b.write(val_b);
    wait(10); //emulate module delay
  }
}
