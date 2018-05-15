#pragma once
#include <string>
#include <exception>
class BaseException : public std::exception {
public:
	BaseException(const std::string &errorMessage) noexcept(true) : errMsg(errorMessage) {}
	~BaseException() noexcept(true) = default;

	virtual const char * what() const noexcept(true)
	{
		return errMsg.c_str();
	}
protected:
	std::string errMsg;
};