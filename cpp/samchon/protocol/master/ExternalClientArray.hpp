#pragma once
#include <samchon/protocol/master/ExternalSystemArray.hpp>

#include <samchon/protocol/IServer.hpp>

namespace samchon
{
	namespace protocol
	{
		namespace master
		{
			class ExternalClient;

			class SAMCHON_FRAMEWORK_API ExternalClientArray
				: public virtual ExternalSystemArray,
				private virtual IServer
			{
				//External Systems are Clients
				//And I'm a Server for them
			protected:
				virtual auto MY_IP() const -> String;
				virtual auto PORT() const -> int;

				String myIP;
				int port;

			public:
				ExternalClientArray(IProtocol*);
				virtual ~ExternalClientArray() = default;

				virtual void construct(std::shared_ptr<library::XML>); //TO DISCARD CREATING CHILDREN BY XML

			protected:
				virtual void addClient(boost::asio::basic_stream_socket<boost::asio::ip::tcp>*);
				virtual auto createChild(boost::asio::basic_stream_socket<boost::asio::ip::tcp>*) -> ExternalClient*;
				
			public:
				virtual void start();
				SHARED_ENTITY_ARRAY_ELEMENT_ACCESSOR_HEADER(ExternalClient)

				virtual auto toXML() const -> std::shared_ptr<library::XML>;
			};
		};
	};
};