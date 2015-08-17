#ifndef _CX3D_GEOMETRYRENDERINFO_H_
#define _CX3D_GEOMETRYRENDERINFO_H_

#include <cstddef>
#include <cstring>

namespace CyberX3D {

class GeometryRenderInfo
{
public:	
	class Attribute 
	{
	public:
		const char* name;
		size_t offset;
		size_t stride;
		size_t attrib_size;
		bool normalized;

		Attribute() : name(NULL), offset(0), stride(0),
			      attrib_size(0), normalized(false) {}

		Attribute(const char* name, size_t offset, size_t stride,
			  size_t attrib_size, bool normalized) 
			: name(name), offset(offset), stride(stride),
			  attrib_size(attrib_size), normalized(normalized)
			  {}

		size_t getIndexForVert(size_t vertex) const
		{
			return (vertex * stride) + offset;
		}

    		bool operator<(const Attribute& b) const {
        		return strcmp(this->name, b.name) < 0 &&
			       this->normalized < b.normalized &&
			       this->offset < b.offset &&
			       this->stride < b.stride &&
			       this->attrib_size < b.attrib_size;
    		}

    		bool operator==(const Attribute& b) const {
        		return strcmp(this->name, b.name) == 0 &&
			       this->normalized == b.normalized &&
			       this->offset == b.offset &&
			       this->stride == b.stride &&
			       this->attrib_size == b.attrib_size;
    		}
	};
	
	static const int MAX_ATTRIBUTES = 16;
	class VertexFormat {
	public:		
		size_t num_attribs;
		size_t size;
		Attribute attribs[MAX_ATTRIBUTES]; 
		VertexFormat() : num_attribs(0), size(0) {}

		void addAttribute(const char* name, size_t offset,
				  size_t stride, size_t attrib_size,
				  bool normalized)
		{
			if (num_attribs < MAX_ATTRIBUTES - 1) {
				size += attrib_size;
				attribs[num_attribs++] = Attribute(name,
					offset, stride, attrib_size, normalized);
			}
		}

    		bool operator<(const VertexFormat& b) const {
        		
			if (this->num_attribs >= b.num_attribs) {
				return false;
			}

			for (int i = 0; i < num_attribs; ++i) {
				const Attribute& attrib_a = this->attribs[i];
				const Attribute& attrib_b = b.attribs[i];
				if (!(attrib_a < attrib_b)) {
					return false;
				}
			}

			return true;
    		}

    		bool operator==(const VertexFormat& b) const {
        		
			if (this->num_attribs != b.num_attribs) {
				return false;
			}

			for (int i = 0; i < num_attribs; ++i) {
				const Attribute& attrib_a = this->attribs[i];
				const Attribute& attrib_b = b.attribs[i];
				if (!(attrib_a == attrib_b)) {
					return false;
				}
			}

			return true;
    		}
	};

	class VertexArray 
	{
	public:
		size_t num_verts;
		size_t num_elements;
		bool instanced;
		VertexFormat format;
		VertexArray() : num_verts(0), num_elements(0), instanced(false) {}

		VertexArray(size_t num_verts, size_t num_elements,
			    bool instanced) 
			: num_verts(num_verts), num_elements(num_elements),
			  instanced(instanced) {}

		size_t getBufferSize() const 
		{
			return num_verts * format.size;
		}
	};

	GeometryRenderInfo() {}
	virtual ~GeometryRenderInfo() {}

	virtual int getNumVertexArrays() { return 0; }
	virtual void getVertexArray(VertexArray&, int) {}

	virtual void getVertexData(const VertexArray&, void *) {}
	virtual void getElementData(const VertexArray&, void *) {}
};

}

#endif
