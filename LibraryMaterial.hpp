#include <string>
class LibraryMaterial
{
    protected:
        int m_Id;
        std::string m_Title;
        int m_Year;

    public:
        LibraryMaterial(){}
        virtual ~LibraryMaterial(){} 
        virtual void Display() = 0; 
        virtual std::string GetTitle() const = 0;
};