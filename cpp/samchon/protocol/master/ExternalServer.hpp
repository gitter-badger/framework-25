#include <samchon/protocol/master/ExternalSystem.hpp>
#include <samchon/protocol/IServerConnector.hpp>

namespace samchon
{
	namespace protocol
	{
		namespace master
		{
			class ExternalServerArray;

			class SAMCHON_FRAMEWORK_API ExternalServer
				: public virtual ExternalSystem,
				public virtual IServerConnector
			{
			private:
				typedef ExternalSystem super;

			protected:
				virtual auto IP() const -> String;
				virtual auto MY_IP() const -> String;
				virtual auto PORT() const -> int;

			public:
				ExternalServer(ExternalServerArray* = nullptr);
				virtual ~ExternalServer() = default;

				virtual void start();
			};
		};
	};
};