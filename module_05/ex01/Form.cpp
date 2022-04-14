#include "Form.h"

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.h"

Form::Form()
  : kSignableGrade_(150),
    kExecutableGrade_(150),
    sign_(false) {
  std::cout << "Form Default Constructor Called\n";
  
}

Form::Form(const Form& other) {
  std::cout << "Form Copy Constructor Called\n";
  *this = other;
}

Form::Form(const std::string& name, const unsigned int signable_grade,
                                    const unsigned int executable_grade)
  : name_(name),
    kSignableGrade_(signable_grade),
    kExecutableGrade_(executable_grade) {
  if (kSignableGrade_ < 1 || kExecutableGrade_ < 1) {
    throw GradeTooHighException();
  }
  if (kSignableGrade_ > 150 || kExecutableGrade_ > 150) {
    throw GradeTooLowException();
  }
  std::cout << "Form Parameterized Constructor Called\n";
}

Form::~Form() {
  std::cout << "Form Destructor Called\n";
}

Form& Form::operator=(const Form& other) {
  std::cout << "Form Copy Operator Called\n";
  *const_cast<std::string*>(&name_) = other.getName();
  *const_cast<unsigned int*>(&kSignableGrade_) = other.getSignableGrade();
  *const_cast<unsigned int*>(&kExecutableGrade_) = other.getExcutableGrade();
  return *this;
}

const std::string& Form::getName() const {
  return name_;
}

unsigned int Form::getSignableGrade() const {
  return kSignableGrade_;
}

unsigned int Form::getExcutableGrade() const {
  return kExecutableGrade_;
}

bool Form::isSigned() const {
  return sign_;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  const unsigned int grade = bureaucrat.getGrade();
  if (getSignableGrade() < grade) {
    throw GradeTooLowException();
  } 
  if (isSigned() == true) {
    throw AlreadySignedException();
  }
  sign_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs) {
  os << "Form: " << rhs.getName() << '\n' <<
        "isSigned: " << (rhs.isSigned() ? "true" : "false") << '\n' <<
        "Signable Grade: " << rhs.getSignableGrade() << '\n' <<
        "Excutable Grade: " << rhs.getExcutableGrade();
  return os;
}