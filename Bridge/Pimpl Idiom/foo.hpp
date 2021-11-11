#pragma once
#include "pimpl.hpp"
class foo {
    class impl;
    pimpl<impl> impl;
};

