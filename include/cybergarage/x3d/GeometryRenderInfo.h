#ifndef _CX3D_GEOMETRYRENDERINFO_H_
#define _CX3D_GEOMETRYRENDERINFO_H_

#include <cstddef>
#include <cstring>
#include <typeinfo>

namespace CyberX3D {

class GeometryRenderInfo
{
public:	
	class Attribute
	{
	public:
		Attribute() : name(NULL), offset(0), components(0),
			  normalized(false), type_size(0),
			  type(&typeid(std::bad_typeid))
			  {}

		Attribute(const char* name, const std::type_info& type,
			  size_t offset, size_t components, bool normalized,
			  size_t type_size) 
			: name(name), type(&type), offset(offset),
			  components(components), normalized(normalized),
			  type_size(type_size)
			  {}

		size_t getByteSize() const
		{
			return components * type_size;
		}

		const char* getName() const
		{
			return name;
		}

		const std::type_info& getType() const
		{
			return *type;
		}

		size_t getOffset() const
		{
			return offset;
		}

		size_t getComponents() const
		{
			return components;
		}

		bool getNormalized() const
		{
			return normalized;
		}

    		bool operator<(const Attribute& b) const 
		{
        		return strcmp(this->name, b.name) < 0 &&
			       this->type->before(*b.type) &&
			       this->normalized < b.normalized &&
			       this->offset < b.offset &&
			       this->components < b.components;
    		}

    		bool operator==(const Attribute& b) const 
		{
        		return strcmp(this->name, b.name) == 0 &&
			       this->type == b.type &&
			       this->normalized == b.normalized &&
			       this->offset == b.offset &&
			       this->components == b.components;
    		}

		static size_t alignAttribute(const Attribute& attrib) 
		{
			size_t byte_size = attrib.getByteSize();
			return byte_size + (byte_size % 4);
		}
 
	private:
		const char* name;
		const std::type_info* type;
		size_t offset;
		size_t components;
		bool normalized;

		size_t type_size;
	};
	
	static const int MAX_ATTRIBUTES = 16;
	class VertexFormat {
	public:		
		VertexFormat() : num_attribs(0), size(0) {}

		const Attribute* getAttribute(size_t id) const
		{
			if (id < num_attribs) {
				return &attribs[id];
			}
			return NULL;
		}

		size_t getNumAttributes() const
		{
			return num_attribs;
		}

		size_t getSize() const
		{
			return size;
		}

		template<class T>
		void addAttribute(const char* name, size_t components,
				  bool normalized = false)
		{
			if (num_attribs < MAX_ATTRIBUTES - 1) {
				attribs[num_attribs] = Attribute(name,
					typeid(T), size, components,
					normalized, T(sizeof(T)));
				size += Attribute::alignAttribute(
						attribs[num_attribs]);
				++num_attribs;
			}
		}

    		bool operator<(const VertexFormat& b) const {
        		
			if (this->num_attribs >= b.num_attribs) {
				return false;
			}

			for (size_t i = 0; i < num_attribs; ++i) {
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

			for (size_t i = 0; i < num_attribs; ++i) {
				const Attribute& attrib_a = this->attribs[i];
				const Attribute& attrib_b = b.attribs[i];
				if (!(attrib_a == attrib_b)) {
					return false;
				}
			}

			return true;
    		}
	private:
		size_t num_attribs;
		size_t size;
		Attribute attribs[MAX_ATTRIBUTES]; 
	};

	class VertexArray 
	{
	public:
		VertexArray() : num_verts(0), num_elements(0),
				instanced(false) {}

		VertexArray(size_t num_verts, size_t num_elements,
			    bool instanced, const VertexFormat& format) 
			: num_verts(num_verts), num_elements(num_elements),
			  instanced(instanced), format(format) {}

		const VertexFormat& getFormat() const 
		{
			return format;
		}

		size_t getNumElements() const 
		{
			return num_elements;
		}

		size_t getNumVertices() const 
		{
			return num_verts;
		}

		size_t getBufferSize() const 
		{
			return num_verts * format.getSize();
		}

	private:		
		size_t num_verts;
		size_t num_elements;
		bool instanced;
		VertexFormat format;
	};

	static size_t getIndexForVert(int vertex, const VertexArray& array,
				      const Attribute& attrib) 
	{
		return (vertex * array.getFormat().getSize())
			 + attrib.getOffset();
	}

	GeometryRenderInfo() {}
	virtual ~GeometryRenderInfo() {}

	virtual size_t getNumVertexArrays() { return 0; }
	virtual void getVertexArray(VertexArray&, size_t) {}

	virtual void getVertexData(void *, size_t) {}
	virtual void getElementData(void *, size_t) {}
};

}

#endif
