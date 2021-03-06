/*
 * IConnection.h
 *
 * Project : 	ApiNewYear
 * Created on:  Jan 2, 2015
 * Author: 	    ApiNewYear Team <zia.apinewyear@gmail.com>
 */

#ifndef APINEWYEAR_ICONNECTION_H
#define APINEWYEAR_ICONNECTION_H

#include <ISocket.h>

namespace ApiNewYear {
	class IHttpClient;
}

namespace ApiNewYear {
	/**
	 * @brief Base class allowing the execution of connection modules in IServer.
	 * @details Establishes the base architecture to allow connection modules to be 
	 * executed by defining how they are executed by the IServer, and what information
	 * the IServer has for each connection module.
	 */
	class IConnection {
	public:
		virtual ~IConnection() {
		}
		/**
		 * @brief Getter for corresponding modules name.
		 * @details IConnection get name of creating module.
		 * @return constant string reference containing the modules name.
		 */
		virtual const std::string& getName(void) const=0;
		/**
		 * @brief Getter for corresponding modules priority.
		 * @details IConnection get the priority of the creating module.
		 * @return int containing the creating modules priority.
		 */
		virtual int getPriority(void) const=0;
		/**
		 * @brief Executes the function passed to the interfaces constructor.
		 * @details IConnection executes the modules main function through a function pointer.
		 *
		 * @param socket server's listening socket.
		 * @param client pointer to the clients information (to be filled!).
		 * @return int containing the success or error code of the modules main function.
		 */
		virtual int update(SOCKET socket, IHttpClient* client)=0;
	
	protected:

	private:
	};
}

#endif