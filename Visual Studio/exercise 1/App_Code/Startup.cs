using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(dai17173.Startup))]
namespace dai17173
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
