#ifndef SHA_HPP
#define SHA_HPP

#include <cryptopp/sha.h>

/**
 * Wrapper class for cryptopp/SHA512
 */
class Sha
{
	public:
		Sha();
		virtual ~Sha();
		/**
		 * Uses data to update internal hash.
		 * @param[in] data inputdata
		 * @param[in] length length of data
		 * @pre \p data is allocated for at least \p length characters
		 * @pre length > 0
		 */
		void update(const char* data, unsigned int length);
		/**
		 * Checks if tha \p hash matches the generated hash.
		 * @param[in] hash hash to compare with
		 * @pre 
		 * @post Sha is reinitialised
		 * @return true if the hashes are equal, false otherwise
		 */
		bool matches(const char* hash);
		/**
		 * Gets the calculated hash.
		 * @param[out] hash pointer to store result in
		 * @pre \p hash is allocated for at least size() characters
		 * @post Sha is reinitialised
		 */
		void getHash(char* hash);
		/**
		 * Gets the size of a generated hash.
		 * @return hashsize in bytes
		 */
		unsigned int size();
		/**
		 * Discards all changes and reinitialises.
		 * @post Sha is reinitialised
		 */
		void reinitialise();
	protected:
		CryptoPP::SHA512* sha;
	private:
};

#endif
