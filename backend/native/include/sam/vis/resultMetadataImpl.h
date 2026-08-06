/*********************************************************************
 *                                                                   *
 *                          DevTools 3.1.0                           *
 *                                                                   *
 *  These coded instructions, statements and computer programs       *
 *  contain unpublished proprietary information of Tech Soft 3D,     *
 *  and are protected by Federal copyright law.  They may not be     *
 *  disclosed to third parties or copied or duplicated in any form,  *
 *  in whole or in part, without the prior written consent of        *
 *  Tech Soft 3D.                                                    *
 *                                                                   *
 *                 Copyright (C) 2026, Tech Soft 3D                  *
 *                                                                   *
 *********************************************************************/
/* ResultMetadata object */
#ifndef RESULTMETADATAIMPL_DEF
#define RESULTMETADATAIMPL_DEF

#include "sam/base/basedefs.h"
#include "sam/vis/visdefs.h"
#include "sam/base/stdcontainers.h"
#include <optional>
#include <ostream>
#include <variant>
#include <string_view>

class vis_ResultMetadataImpl {
  public:
    class Attribute {
      public:
        enum class Type {
            FLOAT,
            DOUBLE,
            INT,
            STRING,
            EMPTY,
        };

        friend std::ostream&
        operator<<(std::ostream& os, const vis_ResultMetadataImpl::Attribute& attribute);

      private:
        vsy::string m_name;
        vsy::vector<std::variant<Vfloat, Vdouble, Vint, vsy::string>> m_values;
        friend class vis_ResultMetadataImpl;
    };

    vis_ResultMetadataImpl();

    /* Custom new/delete operators to use vut_mallocMem/vut_freeMem */
    static void*
    operator new(size_t size);

    static void
    operator delete(void* ptr);

    void
    setName(const Vchar* name);
    vsy::string
    getName() const;
    vis_ResultMetadataImpl::Attribute::Type
    getAttributeType(Vchar* attributeName) const;
    void
    addAttributeInt(const Vchar* name, Vint value);
    void
    addAttributeFloat(const Vchar* name, Vfloat value);
    void
    addAttributeDouble(const Vchar* name, Vdouble value);
    void
    addAttributeString(const Vchar* name, const Vchar* value);
    std::optional<Vint>
    getAttributeValueInt(const Vchar* name);
    std::optional<Vfloat>
    getAttributeValueFloat(const Vchar* name);
    std::optional<Vdouble>
    getAttributeValueDouble(const Vchar* name);
    std::optional<vsy::string>
    getAttributeValueString(const Vchar* name);
    void
    setSize(Vlong length, Vint rowsCount, Vint columnsCount);
    void
    setType(Vint type, Vint subType, Vint entityType);
    void
    setResultType(Vint resultType);
    void
    getDimensions(Vchar dimensions[]) const;
    Vlong
    getLength() const;
    Vint
    getRowsCount() const;
    Vint
    getColumnsCount() const;
    Vint
    getType() const;
    Vint
    getResultType() const;
    Vint
    getEntityType() const;
    Vint
    getSubEntityType() const;

    void
    printAttributes() const;
    void
    storeAttributesNames(vsy_List* attributesNames) const;

    friend std::ostream&
    operator<<(std::ostream& os, const vis_ResultMetadataImpl& metadata);

  private:
    vsy::string m_name;
    vsy::vector<Attribute> m_attributes;
    Vint m_entityType;
    Vint m_subEntityType;
    Vint m_type;
    Vint m_resultType;
    Vint m_rows;
    Vint m_columns;
    Vlong m_length;

    std::optional<vis_ResultMetadataImpl::Attribute>
    findAttribute(vsy::vector<vis_ResultMetadataImpl::Attribute> const& attributes, std::string_view name) const;

    template<typename T>
    void
    addAttributeHelper(vsy::vector<vis_ResultMetadataImpl::Attribute>& attributes, const Vchar* attributeName, T value);

    template<typename T>
    std::optional<T>
    getValueHelper(vsy::vector<vis_ResultMetadataImpl::Attribute>& attributes, const Vchar* attributeName);
};

#endif
