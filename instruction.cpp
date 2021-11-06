#include <cassert>
#include <string>
#include <unordered_map>

#include "instruction.h"
#include "isa.h"

std::string Ins::ToString() const {
  std::string s = "";

  switch (opcode) {
#define OPLIST(code, mnemonic, format)                                         \
  case (Ins::Opcode::code): {                                                  \
    s = Serialize##format(mnemonic);                                           \
  } break;

    INSTRUCTION_LIST(OPLIST)
#undef OPLIST

  default: {
    assert(false);
  }
  }

  return s;
}

std::string Ins::SerializeINT(const char *s) const {
  return std::string(s) + " " + std::to_string(imms[0]);
}

std::string Ins::SerializeINT_INT(const char *s) const {
  return std::string(s) + " " + std::to_string(imms[0]) + ", " +
         std::to_string(imms[1]);
}
