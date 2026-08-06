#ifndef TessDataHelper_header_included
#define TessDataHelper_header_included

#include <vector>
#include <string>
#ifdef VKI_LIBAPI_HOOPS
#include <A3DSDKIncludes.h>

// Copied from ExchangeToolkit.   Ideally would use this directly from the toolkit rather than duplicating here.
// BJF

namespace example52HE {
    void
    setPrintEnabled(bool flag);
    void
    setHoopsLicense(const std::string& license);
    int
    run_example52HE(int argc, char* argv[]);
} // namespace example52HE

struct TessFaceDataHelper {
    /*! \private */
    TessFaceDataHelper(A3DTessFaceData const& d, A3DUns32 const* triangulatedIndexes, A3DUns32 const* wireIndexes)
    {
        A3DUns32 sz_tri_idx = 0u;
        A3DUns32 ti_index = d.m_uiStartTriangulated;
        if (kA3DTessFaceDataTriangle & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tris = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 tri = 0u; tri < num_tris; tri++) {
                for (A3DUns32 vert = 0u; vert < 3u; vert++) {
                    _normals.push_back(triangulatedIndexes[ti_index++]);
                    _vertices.push_back(triangulatedIndexes[ti_index++]);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleFan & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_fans = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 fan_idx = 0u; fan_idx < num_fans; ++fan_idx) {
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++];
                A3DUns32 const root_n = triangulatedIndexes[ti_index++];
                A3DUns32 const root_v = triangulatedIndexes[ti_index++];
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    _normals.push_back(root_n);
                    _vertices.push_back(root_v);

                    _normals.push_back(triangulatedIndexes[ti_index++]);
                    _vertices.push_back(triangulatedIndexes[ti_index++]);

                    _normals.push_back(triangulatedIndexes[ti_index]);
                    _vertices.push_back(triangulatedIndexes[ti_index + 1]);
                }
                ti_index += 2;
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleStripe & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tri_stips = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 strip_idx = 0u; strip_idx < num_tri_stips; ++strip_idx) {
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++];
                ti_index += 2;
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    A3DUns32 const prev_n = triangulatedIndexes[ti_index - 2];
                    A3DUns32 const prev_v = triangulatedIndexes[ti_index - 1];
                    A3DUns32 const current_n = triangulatedIndexes[ti_index++];
                    A3DUns32 const current_v = triangulatedIndexes[ti_index++];
                    A3DUns32 const next_n = triangulatedIndexes[ti_index];
                    A3DUns32 const next_v = triangulatedIndexes[ti_index + 1];

                    _normals.push_back(current_n);
                    _vertices.push_back(current_v);
                    _normals.push_back((vert % 2) ? next_n : prev_n);
                    _vertices.push_back((vert % 2) ? next_v : prev_v);
                    _normals.push_back((vert % 2) ? prev_n : next_n);
                    _vertices.push_back((vert % 2) ? prev_v : next_v);
                }
                ti_index += 2;
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleOneNormal & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tris_1normal = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 tri = 0u; tri < num_tris_1normal; tri++) {
                A3DUns32 n = triangulatedIndexes[ti_index++];
                for (A3DUns32 vert = 0u; vert < 3u; vert++) {
                    _normals.push_back(n);
                    _vertices.push_back(triangulatedIndexes[ti_index++]);
                }
            }
        }

        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleFanOneNormal & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_fans_1normal = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 fan_idx = 0u; fan_idx < num_fans_1normal; ++fan_idx) {
                A3DBool const has_vertex_normals = 0 == (d.m_puiSizesTriangulated[sz_tri_idx] & kA3DTessFaceDataNormalSingle);
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++] & kA3DTessFaceDataNormalMask;
                A3DUns32 const root_n = triangulatedIndexes[ti_index++];
                A3DUns32 const root_v = triangulatedIndexes[ti_index++];
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    A3DUns32 const n = (has_vertex_normals ? triangulatedIndexes[ti_index++] : root_n);
                    A3DUns32 const v = triangulatedIndexes[ti_index++];

                    A3DUns32 const next_n = (has_vertex_normals ? triangulatedIndexes[ti_index] : root_n);
                    A3DUns32 const next_v = triangulatedIndexes[ti_index + (has_vertex_normals ? 1 : 0)];

                    _normals.push_back(root_n);
                    _vertices.push_back(root_v);
                    _normals.push_back(n);
                    _vertices.push_back(v);
                    _normals.push_back(next_n);
                    _vertices.push_back(next_v);
                }
                ti_index += (has_vertex_normals ? 2 : 1);
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleStripeOneNormal & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tri_stips = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 strip_idx = 0u; strip_idx < num_tri_stips; ++strip_idx) {
                A3DBool const has_vertex_normals = 0 == (d.m_puiSizesTriangulated[sz_tri_idx] & kA3DTessFaceDataNormalSingle);
                A3DUns32 const series_normal = triangulatedIndexes[ti_index];
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++] & kA3DTessFaceDataNormalMask;
                ti_index += 2;
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    A3DUns32 const prev_n = (has_vertex_normals ? triangulatedIndexes[ti_index - 2] : series_normal);
                    A3DUns32 const prev_v = triangulatedIndexes[ti_index - 1];

                    A3DUns32 const current_n = (has_vertex_normals ? triangulatedIndexes[ti_index++] : series_normal);
                    A3DUns32 const current_v = triangulatedIndexes[ti_index++];

                    A3DUns32 const next_n = (has_vertex_normals ? triangulatedIndexes[ti_index] : series_normal);
                    A3DUns32 const next_v = triangulatedIndexes[ti_index + (has_vertex_normals ? 1 : 0)];

                    _normals.push_back(current_n);
                    _vertices.push_back(current_v);
                    _normals.push_back((vert % 2) ? next_n : prev_n);
                    _vertices.push_back((vert % 2) ? next_v : prev_v);
                    _normals.push_back((vert % 2) ? prev_n : next_n);
                    _vertices.push_back((vert % 2) ? prev_v : next_v);
                }
                ti_index += (has_vertex_normals ? 2 : 1);
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleTextured & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tris = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 tri_idx = 0u; tri_idx < num_tris; tri_idx++) {
                for (A3DUns32 vert_idx = 0u; vert_idx < 3u; vert_idx++) {
                    _normals.push_back(triangulatedIndexes[ti_index++]);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index++]);
                    }
                    _vertices.push_back(triangulatedIndexes[ti_index++]);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleFanTextured & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_fans_textured = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 fan_idx = 0u; fan_idx < num_fans_textured; ++fan_idx) {
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++];
                A3DUns32 const n = triangulatedIndexes[ti_index++];
                std::vector<A3DUns32> t;
                for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                    t.push_back(triangulatedIndexes[ti_index++]);
                }
                A3DUns32 const v = triangulatedIndexes[ti_index++];
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    _normals.push_back(n);
                    _texture.insert(_texture.end(), t.begin(), t.end());
                    _vertices.push_back(v);

                    _normals.push_back(triangulatedIndexes[ti_index++]);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index++]);
                    }
                    _vertices.push_back(triangulatedIndexes[ti_index++]);

                    _normals.push_back(triangulatedIndexes[ti_index++]);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index++]);
                    }
                    _vertices.push_back(triangulatedIndexes[ti_index++]);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleStripeTextured & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tri_stips = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 strip_idx = 0u; strip_idx < num_tri_stips; ++strip_idx) {
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++];
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    A3DUns32 const prev_n = triangulatedIndexes[ti_index - (2 + d.m_uiTextureCoordIndexesSize)];
                    std::vector<A3DUns32> prev_t;
                    for (A3DUns32 i = ti_index - (1 + d.m_uiTextureCoordIndexesSize); i < ti_index - 1; ++i) {
                        prev_t.push_back(triangulatedIndexes[i]);
                    }
                    A3DUns32 const prev_v = triangulatedIndexes[ti_index - 1];

                    A3DUns32 const current_n = triangulatedIndexes[ti_index++];
                    std::vector<A3DUns32> current_t;
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        current_t.push_back(triangulatedIndexes[ti_index++]);
                    }
                    A3DUns32 const current_v = triangulatedIndexes[ti_index++];

                    A3DUns32 const next_n = triangulatedIndexes[ti_index];
                    std::vector<A3DUns32> next_t;
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        next_t.push_back(triangulatedIndexes[ti_index + i + 1]);
                    }
                    A3DUns32 const next_v = triangulatedIndexes[ti_index + 1 + d.m_uiTextureCoordIndexesSize];

                    _normals.push_back(current_n);
                    _texture.insert(_texture.end(), current_t.begin(), current_t.end());
                    _vertices.push_back(current_v);

                    _normals.push_back((vert % 2) ? next_n : prev_n);
                    _texture.insert(_texture.end(), (vert % 2) ? next_t.begin() : prev_t.begin(),
                                    (vert % 2) ? next_t.end() : prev_t.end());
                    _vertices.push_back((vert % 2) ? next_v : prev_v);

                    _normals.push_back((vert % 2) ? prev_n : next_n);
                    _texture.insert(_texture.end(), (vert % 2) ? prev_t.begin() : next_t.begin(),
                                    (vert % 2) ? prev_t.end() : next_t.end());
                    _vertices.push_back((vert % 2) ? prev_v : next_v);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleOneNormalTextured & d.m_usUsedEntitiesFlags) {
            A3DBool const has_vertex_normals = 0 == (d.m_puiSizesTriangulated[sz_tri_idx] & kA3DTessFaceDataNormalSingle);
            A3DUns32 const series_normal = triangulatedIndexes[ti_index];
            A3DUns32 const num_tris_1normal_textured = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 tri = 0u; tri < num_tris_1normal_textured; tri++) {
                for (A3DUns32 vert = 0u; vert < 3u; vert++) {
                    _normals.push_back(has_vertex_normals ? triangulatedIndexes[ti_index++] : series_normal);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index++]);
                    }
                    _vertices.push_back(triangulatedIndexes[ti_index++]);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx && kA3DTessFaceDataTriangleFanOneNormalTextured & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_fans_textured = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 fan_idx = 0u; fan_idx < num_fans_textured; ++fan_idx) {
                A3DUns32 const root_n = triangulatedIndexes[ti_index++];
                std::vector<A3DUns32> root_t;
                for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                    root_t.push_back(triangulatedIndexes[ti_index++]);
                }
                A3DUns32 const root_v = triangulatedIndexes[ti_index++];
                A3DBool const has_vertex_normals = 0 == (d.m_puiSizesTriangulated[sz_tri_idx] & kA3DTessFaceDataNormalSingle);
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++] & kA3DTessFaceDataNormalMask;
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    _normals.push_back(root_n);
                    _texture.insert(_texture.end(), root_t.begin(), root_t.end());
                    _vertices.push_back(root_v);

                    _normals.push_back(has_vertex_normals ? triangulatedIndexes[ti_index++] : root_n);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index++]);
                    }
                    _vertices.push_back(triangulatedIndexes[ti_index++]);

                    _normals.push_back(has_vertex_normals ? triangulatedIndexes[ti_index] : root_n);
                    for (A3DUns32 i = 0u; i < d.m_uiTextureCoordIndexesSize; ++i) {
                        _texture.push_back(triangulatedIndexes[ti_index + i + 1]);
                    }
                    _vertices.push_back(
                    triangulatedIndexes[ti_index + 1 + (has_vertex_normals ? d.m_uiTextureCoordIndexesSize : 0)]);
                }
            }
        }
        if (d.m_uiSizesTriangulatedSize > sz_tri_idx &&
            kA3DTessFaceDataTriangleStripeOneNormalTextured & d.m_usUsedEntitiesFlags) {
            A3DUns32 const num_tri_stips = d.m_puiSizesTriangulated[sz_tri_idx++];
            for (A3DUns32 strip_idx = 0u; strip_idx < num_tri_stips; ++strip_idx) {
                A3DBool const has_vertex_normals = 0 == (d.m_puiSizesTriangulated[sz_tri_idx] & kA3DTessFaceDataNormalSingle);
                A3DUns32 const num_pts = d.m_puiSizesTriangulated[sz_tri_idx++] & kA3DTessFaceDataNormalMask;
                A3DUns32 const series_normal = triangulatedIndexes[ti_index];
                ti_index += 2 + d.m_uiStyleIndexesSize;
                for (A3DUns32 vert = 1u; vert < num_pts - 1u; vert++) {
                    A3DUns32 const prev_n =
                    has_vertex_normals ? triangulatedIndexes[ti_index - (2 + d.m_uiTextureCoordIndexesSize)] : series_normal;
                    A3DUns32 const prev_v = triangulatedIndexes[ti_index - 1];

                    A3DUns32 const current_n = has_vertex_normals ? triangulatedIndexes[ti_index++] : series_normal;
                    ti_index += d.m_uiTextureCoordIndexesSize;
                    A3DUns32 const current_v = triangulatedIndexes[ti_index++];

                    A3DUns32 const next_n = has_vertex_normals ? triangulatedIndexes[ti_index] : series_normal;
                    A3DUns32 const next_v =
                    triangulatedIndexes[ti_index + 1 + (has_vertex_normals ? d.m_uiTextureCoordIndexesSize : 0)];

                    _normals.push_back(current_n);
                    _vertices.push_back(current_v);
                    _normals.push_back((vert % 2) ? next_n : prev_n);
                    _vertices.push_back((vert % 2) ? next_v : prev_v);
                    _normals.push_back((vert % 2) ? prev_n : next_n);
                    _vertices.push_back((vert % 2) ? prev_v : next_v);
                }
            }
        }

        A3DUns32 wi_index = d.m_uiStartWire;
        TessLoop current_loop;
        for (A3DUns32 idx = 0u; idx < d.m_uiSizesWiresSize; ++idx) {
            A3DUns32 const nverts_with_flags = d.m_puiSizesWires[idx];
            A3DUns32 const nvertices = nverts_with_flags & ~kA3DTessFaceDataWireIsClosing & ~kA3DTessFaceDataWireIsNotDrawn;
            A3DBool const is_closing = (nverts_with_flags & kA3DTessFaceDataWireIsClosing) ? A3D_TRUE : A3D_FALSE;
            A3DBool const is_hidden = (nverts_with_flags & kA3DTessFaceDataWireIsNotDrawn) ? A3D_TRUE : A3D_FALSE;
            TessEdge current_edge;
            current_edge._visible = !is_hidden;
            for (A3DUns32 vidx = 0u; vidx < nvertices; ++vidx) {
                current_edge._vertices.push_back(wireIndexes[wi_index++]);
            }
            current_loop._edges.push_back(current_edge);

            if (is_closing) {
                _loops.push_back(current_loop);
                current_loop._edges.clear();
            }
        }
    }

    TessFaceDataHelper(TessFaceDataHelper const& other):
        _vertices(other._vertices), _normals(other._normals), _texture(other._texture)
    {
    }

    /*! \private */
    TessFaceDataHelper&
    operator=(TessFaceDataHelper const& other)
    {
        _vertices = other._vertices;
        _normals = other._normals;
        _texture = other._texture;
        return *this;
    }

    /*! \brief Gets the list of vertex index values defining the
     *  triangles of the mesh for this face. The length of
     *  this vector should be a multiple of 3. Index values should
     *  be accessed as triplets, each value defining the offset in
     *  the TessBaseInstance::coords() array.
     */
    std::vector<A3DUns32> const&
    vertices(void) const
    {
        return _vertices;
    }

    /*! \brief Gets the list of vertex index values defining the
     *  normal vectors at each vertex location. The length of
     *  this vector should be a multiple of 3. Index values should
     *  be accessed as triplets, each value defining the offset in
     *  the Tess3DInstance::normals() array.
     */
    std::vector<A3DUns32> const&
    normals(void) const
    {
        return _normals;
    }

    /*! \brief Gets the list of texture coordinate values.
     *  \todo Explain this better
     */
    std::vector<A3DUns32> const&
    textures(void) const
    {
        return _texture;
    }

    /*! \brief Index list of vertices for the tessellation of
     *  a specific edge.
     */
    struct TessEdge {
        /*! \brief Array indexes for the vertices */
        std::vector<A3DUns32> _vertices;
        /*! \brief Visibility flag */
        bool _visible = false;
    };

    /*! \brief A collection of TessEdge objects representing
     *  a single closed series of edges that bound a face.
     */
    struct TessLoop {
        /*! \brief Collection of edges that make up this loop */
        std::vector<TessEdge> _edges;
    };

    /*! \brief Provides a list of TessLoop objects representing the
     * edge loops that bound this face.
     */
    std::vector<TessLoop> const&
    loops(void) const
    {
        return _loops;
    }

    std::vector<A3DUns32> _vertices, _normals, _texture;
    std::vector<TessLoop> _loops;
};
#endif

#endif
