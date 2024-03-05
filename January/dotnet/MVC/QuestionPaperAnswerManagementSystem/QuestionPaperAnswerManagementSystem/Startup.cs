using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(QuestionPaperAnswerManagementSystem.Startup))]
namespace QuestionPaperAnswerManagementSystem
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
