/*
 * ptrtree: implementaion of tree.hh using pointers
 * Written by Alex Grant
 */

#include "ptrtree.hh"

namespace tree {

///////////////////////////////////////////////////////////////////////////////
PtrTree::PtrTree(value_t value)
    : Tree(), value_(value), left_(nullptr), right_(nullptr)
    // since no children have been specified, set them to leaves
{ }

///////////////////////////////////////////////////////////////////////////////
PtrTree::PtrTree(value_t value, const PtrTree& left, const PtrTree& right)
    : Tree(), value_(value), left_(&left), right_(&right) 
{ }

///////////////////////////////////////////////////////////////////////////////
unsigned
PtrTree::size() const
{
    unsigned retval = 1; // value to return
    if (left_ != nullptr){
        retval += left_->size();
    }
    if (right_ != nullptr){
        retval += right_->size();
    }
    // size will be 1 if this is leaf 
    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// Scan vector for first ocurrence of value, then build path back up to root
std::string
PtrTree::pathTo(value_t value) const
{
    if (value == 0) {
        return "0";
    } 
    return "";
}


///////////////////////////////////////////////////////////////////////////////
// Follow path from root to end of string, returning value when done
PtrTree::value_t
PtrTree::getByPath(const std::string& path) const
{
    std::string beep = path;
    return value_;
}
} // end namespace
