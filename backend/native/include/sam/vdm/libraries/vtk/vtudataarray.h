/**
 * vtuDataArray is the class used for data array objects
 * containing numeric data.
 */
#ifndef VTUDATAARRAY_DEF
#define VTUDATAARRAY_DEF

#include "sam/base/basedefs.h"
#include "sam/vdm/libraries/vtk/vtuxmlwriter.h"

enum class DataArrayType { VTK_DATA_ARRAY, VTK_ARRAY };

template<typename T>
class vtuDataArray {
  public:
    vtuDataArray(size_t tuplesCount, Vint numberOfComponents, DataArrayType arrayType):
        m_name(NULL), m_numberOfTuples(tuplesCount), m_nbComponents(numberOfComponents),
        m_dataArray((tuplesCount * numberOfComponents > 0) ? (T*)vut_mallocMem(tuplesCount * numberOfComponents * sizeof(T)) :
                                                             nullptr),
        m_dataType(VTKTypeSelector(m_dataArray)), m_dataArrayType(arrayType), m_componentsNames(numberOfComponents)
    {
    }
    ~vtuDataArray()
    {
        if (m_name) {
            vut_freeMem(m_name);
        }
        if (m_dataArray) {
            vut_freeMem(m_dataArray);
        }
        m_name = nullptr;
        m_dataArray = nullptr;
    }
    size_t
    getNumberOfTuples() const
    {
        return m_numberOfTuples;
    }
    void
    setNumberOfTuples(size_t tuplesCount)
    {
        m_numberOfTuples = tuplesCount;
    }
    Vint
    getNumberOfComponents() const
    {
        return m_nbComponents;
    }
    T
    getValue(size_t index) const
    {
        return m_dataArray[index];
    }
    void
    setValue(size_t index, T value)
    {
        m_dataArray[index] = value;
    }
    void
    setValues(size_t index, size_t nbValues, const T* values)
    {
        memcpy(&m_dataArray[index], values, nbValues * sizeof(T));
    }
    void
    setName(Vchar* dataArrayName)
    {
        if (m_name == NULL) {
            m_name = (Vchar*)vut_mallocMem(SYS_MAXNAMECHAR * sizeof(Vchar));
        }
        vut_copyNameString(dataArrayName, m_name, SYS_MAXNAMECHAR);
    }
    Vchar*
    getName() const
    {
        return m_name;
    }
    DataArrayType
    getDataArrayType() const
    {
        return m_dataArrayType;
    }
    void
    addComponentName(vsy::string componentName)
    {
        m_componentsNames.push_back(componentName);
    }
    // get the name of the ith component of dataArray
    const Vchar*
    getComponentName(Vint componentIndex) const
    {
        if (componentIndex >= m_nbComponents || componentIndex < 0) {
            return nullptr;
        }
        if (m_componentsNames[componentIndex].empty()) {
            return nullptr;
        }
        else {
            return m_componentsNames[componentIndex].c_str();
        }
    }
    // compute range of the L2Norm of dataArray:
    std::pair<Vdouble, Vdouble>
    getDataArrayRangesDouble() const
    {
        Vdouble max_norm = std::numeric_limits<Vdouble>::lowest();
        Vdouble min_norm = -max_norm;

        Vlong index = 0;
        for (size_t tuple = 0; tuple < m_numberOfTuples; tuple++) {
            Vdouble value = 0.;
            for (Vint i = 0; i < m_nbComponents; i++) {
                value += static_cast<double>(m_dataArray[index]) * m_dataArray[index];
                index++;
            }
            Vdouble norm = std::sqrt(value);
            if (norm < min_norm) {
                min_norm = norm;
            }
            if (norm > max_norm) {
                max_norm = norm;
            }
        }
        return {min_norm, max_norm};
    }
    static Vint
    VTKTypeSelector(Vint* array)
    {
        return SYS_INTEGER;
    }
    static Vint
    VTKTypeSelector(Vfloat* array)
    {
        return SYS_FLOAT;
    }
    static Vint
    VTKTypeSelector(Vdouble* array)
    {
        return SYS_DOUBLE;
    }
    static Vint
    VTKTypeSelector(Vlong* array)
    {
        return SYS_LONG;
    }
    static Vint
    VTKTypeSelector(vsy::string* array)
    {
        return SYS_STRING;
    }

    Vint
    getDataType() const
    {
        return m_dataType;
    }

    static inline size_t
    getWordTypeSize()
    {
        return sizeof(T);
    }

    const T*
    getDataArrayPointer() const
    {
        return m_dataArray;
    }

  private:
    Vchar* m_name;                 // name of the dataArray, may be NULL
    size_t m_numberOfTuples;       // number of dataArray entries
    Vint m_nbComponents;           // dataArray component number: scalar=1 default not written in attributes
    T* m_dataArray;                // pointer to template vector
    Vint m_dataType;               // data type in Access type: SYS_INT,SYS_FLOAT,...
    DataArrayType m_dataArrayType; // Array type, so far only DataArray used
    vsy::vector<vsy::string> m_componentsNames;
};

#endif
