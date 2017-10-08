// Copyright 2017 Global Phasing Ltd.

// This file exists to make compilation of gemmi-convert faster.

#define STB_SPRINTF_IMPLEMENTATION
#include "gemmi/to_mmcif.hpp"
#include "gemmi/to_pdb.hpp"

void write_pdb(const gemmi::Structure& st, std::ostream& os,
               bool iotbx_compat) {
  gemmi::write_pdb(st, os, iotbx_compat);
}

void update_cif_block(const gemmi::Structure& st,
                      gemmi::cif::Block& block) {
  gemmi::update_cif_block(st, block);
}

// vim:sw=2:ts=2:et:path^=../include,../third_party
