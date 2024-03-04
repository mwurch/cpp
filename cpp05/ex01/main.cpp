#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat steven = Bureaucrat("Steven", 150);
	Bureaucrat olaf = Bureaucrat("Olaf", 1);

	Form Antrag1 = Form("Kindergeld Antrag", 150, 50);
	Form Antrag2 = Form("Anmeldung einer Wohnung", 1, 50);

	//everything OK
	steven.signForm(Antrag1);
	olaf.signForm(Antrag2);
	// Grade too Low KO
	steven.signForm(Antrag2);
	// already signed KO
	olaf.signForm(Antrag1);
}