#include "sha.hpp"

Sha::Sha()
{
	this->sha = new CryptoPP::SHA512();
}

Sha::~Sha()
{
	delete this->sha;
	this->sha = NULL;
}

void Sha::update(const char* data, unsigned int length)
{
	this->sha->Update((const byte*)data, length);
}

bool Sha::matches(const char* hash)
{
	return this->sha->Verify((const byte*)hash);
}

void Sha::getHash(char* hash)
{
	this->sha->Final((byte*)hash);
}

unsigned int Sha::size()
{
	return this->sha->DigestSize();
}

void Sha::reinitialise()
{
	this->sha->Restart();
}
