using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(dai171733.Startup))]
namespace dai171733
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
