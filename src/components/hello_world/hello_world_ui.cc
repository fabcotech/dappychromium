#include "components/hello_world/hello_world_ui.h"

#include "components/grit/components_scaled_resources.h"
#include "components/grit/dev_ui_components_resources.h"
#include "components/hello_world/constants.h"
#include "components/strings/grit/components_strings.h"
#include "content/public/browser/browser_context.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_ui.h"
#include "content/public/browser/web_ui_data_source.h"

HelloWorldUI::HelloWorldUI(content::WebUI* web_ui)
    : content::WebUIController(web_ui) {
  // Set up the chrome://hello-world source.
  content::WebUIDataSource* html_source =
      content::WebUIDataSource::CreateAndAdd(
          web_ui->GetWebContents()->GetBrowserContext(),
          chrome::kChromeUIHelloWorldHost);

  // Localized strings.
  static constexpr webui::LocalizedString kStrings[] = {
      {"helloWorldTitle", IDS_HELLO_WORLD_TITLE},
      {"welcomeMessage", IDS_HELLO_WORLD_WELCOME_TEXT},
  };
  html_source->AddLocalizedStrings(kStrings);

  // As a demonstration of passing a variable for JS to use we pass in the name "Bob".
  html_source->AddString("userName", "Bob");
  html_source->UseStringsJs();

  // Add required resources.
  static constexpr webui::ResourcePath kResources[] = {
      {"hello_world.html", IDR_HELLO_WORLD_HTML},
      {"hello_world.css", IDR_HELLO_WORLD_CSS},
      {"hello_world.js", IDR_HELLO_WORLD_JS},
  };
  source->AddResourcePaths(kResources);
  html_source->SetDefaultResource(IDR_HELLO_WORLD_HTML);
}

HelloWorldUI::~HelloWorldUI() {
}