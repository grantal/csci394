/*
 * ptrtree.hh: API for a tree based on pointers rather than arrays
 * unlike vectree, you can make unbalanced trees
 * Written by Alex Grant.
 * adapted from vectree.hh by Eitan Frachtenberg.
 */

#pragma once

#include <ostream>
#include <string>

#include "tree.hh"

namespace tree {

class PtrTree : public Tree {
  public:
    PtrTree(value_t value);
    ~PtrTree() = default;
    PtrTree(value_t newroot, const PtrTree& left, const PtrTree& right);

    virtual unsigned size() const override;

    virtual std::string pathTo(value_t value) const override;

    value_t getByPath(const std::string& path) const override;

  private:
    const value_t value_;
    const PtrTree* left_;
    const PtrTree* right_;
};


} // namespace
