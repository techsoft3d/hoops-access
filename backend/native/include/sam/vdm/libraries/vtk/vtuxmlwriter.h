/* vtuXMLWriter object */
#ifndef VTUXMLWRITER_DEF
#define VTUXMLWRITER_DEF

#include <ostream>
#include "sam/base/basedefs.h"
#include "sam/base/stdcontainers.h"
#include "sam/vdm/libraries/vtk/vtudataarray.h"

// The output stream to which the XML is written.
/**
 * Enumerate big and little endian byte order settings.
 */
enum class ByteOrder { VTK_BIG_ENDIAN, VTK_LITTLE_ENDIAN };

/**
 * Enumerate the supported data modes.
 * Ascii = Inline ascii data.
 * Binary = Inline binary data (base64 encoded, possibly compressed).
 * Appended = Appended binary data (possibly compressed and/or base64).
 */
enum class FormatType { Ascii, Binary, Appended };

/**
 * Enumerate the supported vtkIdType bit lengths.
 * Int32 = File stores 32-bit values for vtkIdType.
 * Int64 = File stores 64-bit values for vtkIdType.
 */
enum class IdType { VTK_INT32 = 32, VTK_INT64 = 64 };

/**
 * Enumerate the supported binary data header bit lengths.
 * UInt32 = File stores 32-bit binary data header elements.
 * UInt64 = File stores 64-bit binary data header elements.
 */
enum class HeaderType { VTK_UINT32 = 32, VTK_UINT64 = 64 };

enum class Compressor : Vint { VTK_ZLIB_DATA_COMPRESSOR, VTK_NO_DATA_COMPRESSOR };

enum class ZCompressionLevel : Vint {
    NoCompression = 0 /*Z_NO_COMPRESSION*/,
    BestSpeed = 1 /*Z_BEST_SPEED*/,
    BestCompression = 9 /*Z_BEST_COMPRESSION*/,
    DefaultCompression = -1 /*Z_DEFAULT_COMPRESSION*/
};

class vtuIndentation {
  public:
    explicit vtuIndentation(Vint ind = 0) { m_indentation = ind; }
    /**
     * Determine the next indentation level. Keep indenting by two until the
     * max of forty.
     */
    vtuIndentation
    getNextIndentation() const;
    vtuIndentation
    getPreviousIndentation() const;

    /**
     * Print out the indentation. Basically output a bunch of spaces.
     */
    friend std::ostream&
    operator<<(std::ostream& os, const vtuIndentation& o);

  protected:
    Vint m_indentation;
};

class vtuXMLWriter {
  public:
    vtuXMLWriter();
    ~vtuXMLWriter();
    Vint
    openFile(const vsy::string& fileName);
    void
    closeFile();

    // write Att
    template<class T>
    Vint
    WriteScalarAttribute(const Vchar* name, const T& data);

    template<class T>
    Vint
    WriteVectorAttribute(const Vchar* name, Vint length, const T& data);

    void
    WriteFileAttributes();
    Vint
    WriteStringAttribute(const Vchar* name, const Vchar* value);
    FormatType
    getWrittingFormat() const;
    void
    setWritingFormat(Vint writtingFormat);

    Vint
    getErrorCode();

    // write inline <Points> datablock: unique DataArray with nodes coordinates
    template<typename T>
    void
    WritePointsInline(const vtuDataArray<T>& points, vtuIndentation indent, FormatType format);

    // write inline <Cells> datablock: 3 DataArrays:connectivity , offset and types
    template<typename T>
    void
    WriteCellsInline(const vtuDataArray<T>& connectivity, const vtuDataArray<T>& offSets, const vtuDataArray<T>& cellTypes,
                     const vtuDataArray<Vlong>& faceoffsets, const vtuDataArray<T>& faces, vtuIndentation indent,
                     FormatType format);

    // Write inline generic DatataArray in ascii or binary. Write header and data
    template<typename T>
    void
    WriteArrayInline(const vtuDataArray<T>& data, vtuIndentation indent, FormatType format, const Vchar* alternateName,
                     Vint writeNumTuples);
    // write a vtuDataArray data block in Ascii mode
    template<typename T>
    Vint
    WriteAsciiData(const vtuDataArray<T>& data, vtuIndentation indent);

    // write a vtuDataArray data block in Binary mode
    template<typename T>
    Vint
    WriteInLineBinaryData(const vtuDataArray<T>& data, vtuIndentation indent);

    // Write a dataArray header with attributes: type, Name, NumberOfComponents, ...
    template<typename T>
    void
    WriteArrayHeader(const vtuDataArray<T>& data, vtuIndentation indent, FormatType format, const Vchar* alternateName,
                     Vint writeNumTuples);
    // Write format: FormatType.
    Vint
    WriteDataModeAttribute(const char* name);

    // close the <DataArray> or <Array> block
    template<typename T>
    Vint
    WriteArrayFooter(const vtuDataArray<T>& data, vtuIndentation indent, Vint shortFormat);

    // convert Access type:(SYS_:STRING/FLOAT/DOUBLE/..) to VTK type name("String"/"Float32"/"Float64"/...)
    const char*
    GetWordTypeName(Vint dataType) const;

    const char*
    GetByteOrderAsString() const;

    void
    setHeaderType(Vint headerType);

    void
    setCompressor(Vint zLibCompression, Vint compressionLevel);

  public:
    std::ostream* m_outFile;

  private:
    Vint m_ierr;
    // The output byte order.
    ByteOrder m_byteOrder;
    // The output binary header word type: HEADERUINT32/HEADERUINT64
    HeaderType m_headerType;
    // compressor type used for dataArray in binary mode: VTK_ZLIB_DATA_COMPRESSOR/VTK_NO_DATA_COMPRESSOR
    Compressor m_compressor;
    ZCompressionLevel m_compressionLevel;
    // dataArray mode: Ascii/Binary/appended
    FormatType m_writingFormat;
    size_t m_blockSize;
};

#endif
