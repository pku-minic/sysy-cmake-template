#include <cassert>
#include <fstream>
#include <unordered_map>

using namespace std;

std::unordered_map<char, const char *> generator = {
    {'e', R"(f_main [0]
  return 0
end f_main
)"},
    {'t', R"(f_main [0]
  return 0
end f_main
)"},
    {'r', R"(  .text
  .align 2
  .global main
main:
  li a0, 0
  ret
)"},
};

int main(int argc, const char *argv[]) {
  assert(argc == 5 || argc == 6);
  char mode = argc == 6 ? argv[2][1] : 'r';
  ofstream ofs(argv[argc == 6 ? 5 : 4]);
  ofs << generator[mode];
  return 0;
}
