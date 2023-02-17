#ifndef COMPONENTS_HELLO_WORLD_HELLO_WORLD_UI_H_
#define COMPONENTS_HELLO_WORLD_HELLO_WORLD_UI_H_
#pragma once

#include "content/public/browser/web_ui_controller.h"

// The WebUI for chrome://hello-world
class HelloWorldUI : public content::WebUIController {
 public:
  explicit HelloWorldUI(content::WebUI* web_ui);
  HelloWorldUI(const HelloWorldUI&) = delete;
  HelloWorldUI& operator=(const HelloWorldUI&) = delete;
  ~HelloWorldUI() override;
 private:
};

#endif  // COMPONENTS_HELLO_WORLD_HELLO_WORLD_UI_H_