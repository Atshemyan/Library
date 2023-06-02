class Journal : public LibraryMaterial
{
    private:
        int volume; 
        int issue; 
        std::string subject; 

    public:
        Journal(int id, std::string title, int year, int volume, int issue, std::string subject)
        { 
            this->m_Id = id;
            this->m_Title = title;
            this->m_Year = year;
            this->volume = volume;
            this->issue = issue;
            this->subject = subject;
        }

        std::string GetTitle() const override
        {
            return this->m_Title;
        }

        void Display() override 
        { 
            std::cout << "ID: " << m_Id << "\nTitle: " << m_Title << "\nVolume: " << volume << "\nIssue: " << issue << "\nSubject: " << subject << "\nYear of Publication: " << m_Year << "\n\n";
        }
};