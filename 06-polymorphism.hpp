#pragma once
#include <string>
#include <cstddef>

/* abstract and interfaces */
class APhone
{
	public:
		virtual ~APhone() = 0;

		virtual void	call(const std::string &number) const = 0;

	protected:
		APhone(const std::string &colour, size_t storage, size_t ram);

		std::string		colour;
		size_t			storage;
		size_t			ram;

	private:
		APhone();
};

class IOperatingSystem
{
	public:
		virtual ~IOperatingSystem() = 0;

		virtual void	printInfo() const = 0;
		virtual void	version() const = 0;
};

/* operating systems */
class iOS : public IOperatingSystem
{
	public:
		virtual ~iOS() = 0;

		void			printInfo() const;
		virtual void	version() const = 0;

	protected:
		iOS();
};

class android : public IOperatingSystem
{
	public:
		virtual ~android() = 0;

		void			printInfo() const;
		virtual void	version() const = 0;

	protected:
		android();
};

/* Brands */
class Apple : public APhone, public iOS
{
	public:
		virtual ~Apple() = 0;

	protected:
		Apple(const std::string &colour, size_t storage, size_t ram);

	private:
		Apple();
};

class Samsung : public APhone, public android
{
	public:
		virtual ~Samsung() = 0;

	protected:
		Samsung(const std::string &colour, size_t storage, size_t ram);

	private:
		Samsung();
};


/* phones */
class iPhone16 : public Apple
{
	public:
		iPhone16(const std::string &colour, size_t storage, size_t ram);
		~iPhone16();

		void	call(const std::string &number) const;
		void	version() const;

	private:
		iPhone16();
};

class iPhone17 : public Apple
{
	public:
		iPhone17(const std::string &colour, size_t storage, size_t ram);
		~iPhone17();

		void	call(const std::string &number) const;
		void	version() const;

	private:
		iPhone17();
};

class GalaxyS24 : public Samsung
{
	public:
		GalaxyS24(const std::string &colour, size_t storage, size_t ram);
		~GalaxyS24();

		void	call(const std::string &number) const;
		void	version() const;

	private:
		GalaxyS24();
};

class GalaxyS25 : public Samsung
{
	public:
		GalaxyS25(const std::string &colour, size_t storage, size_t ram);
		~GalaxyS25();

		void	call(const std::string &number) const;
		void	version() const;

	private:
		GalaxyS25();
};
