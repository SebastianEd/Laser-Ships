#pragma once

template <class T>
class TSingleton
{
protected:

	// Membervariables
	static T *m_pSingleton;   //Static Object

public:

	// Memberfunctions

	// Destructor
	//
	virtual ~TSingleton()
	{
	}

	// Get
	//
	// If needed: Create static object and 
	// return pointer on this object. 
	//
	inline static T* Get()
	{
		// Is there already an instance?
		if (!m_pSingleton)
			m_pSingleton = new T;   //No, create new instance
								
		return (m_pSingleton);		// return pointer on this instance

	} // Get

	  // Free static object
	  //
	static void Del()
	{
		//Is there already an instance ?
		if (m_pSingleton)
		{
			delete (m_pSingleton);  // If yes, free
			m_pSingleton = nullptr;    // and set ponter to nullptr
		}

	} // Del

};

// initialize static variable
//
template <class T>
T* TSingleton<T>::m_pSingleton = 0;
