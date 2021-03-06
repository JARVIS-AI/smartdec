/* * SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
 * Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
 * Alexander Fokin, Sergey Levin, Leonid Tsvetkov
 *
 * This file is part of SmartDec decompiler.
 *
 * SmartDec decompiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SmartDec decompiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <nc/config.h>

#include "Declaration.h"

namespace nc {
namespace core {
namespace likec {

/**
 * Label in function code.
 */
class LabelDeclaration: public Declaration {
    int referenceCount_; ///< Number of references to this label in the code.

public:
    /**
     * Class constructor.
     *
     * \param[in] tree Owning tree.
     * \param[in] identifier Name of the label.
     */
    LabelDeclaration(Tree &tree, const QString &identifier):
        Declaration(tree, LABEL_DECLARATION, identifier), referenceCount_(0)
    {}

    virtual LabelDeclaration *rewrite() override { return this; }

    /**
     * Increments reference count.
     */
    void addReference() { ++referenceCount_; }

    /**
     * \return Reference count.
     */
    int referenceCount() const { return referenceCount_; }

protected:
    virtual void doPrint(PrintContext &context) const override;
};

} // namespace likec
} // namespace core
} // namespace nc

NC_REGISTER_CLASS_KIND(nc::core::likec::Declaration, nc::core::likec::LabelDeclaration, nc::core::likec::Declaration::LABEL_DECLARATION)

/* vim:set et sts=4 sw=4: */
