// Copyright 2022 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_PLUGIN_TIZEN_APP_MANAGER_H_
#define FLUTTER_PLUGIN_TIZEN_APP_MANAGER_H_

#include <flutter/event_channel.h>
#include <flutter/event_sink.h>
#include <flutter/event_stream_handler_functions.h>

#include "application_utils.h"

class TizenAppManagerPlugin : public flutter::Plugin {
 public:
  using MethodResultPtr =
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>>;
  static void RegisterWithRegistrar(flutter::PluginRegistrar *registrar);
  flutter::EncodableList &Applications();
  std::unique_ptr<flutter::EventSink<flutter::EncodableValue>> launch_events_;
  std::unique_ptr<flutter::EventSink<flutter::EncodableValue>>
      terminate_events_;

  TizenAppManagerPlugin();

  virtual ~TizenAppManagerPlugin();

 private:
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      MethodResultPtr result);
  void RegisterObserver(
      std::unique_ptr<flutter::EventSink<flutter::EncodableValue>> &&events);
  void UnregisterObserver();
  void GetCurrentId(MethodResultPtr result);
  void GetApplicationInfo(const flutter::EncodableValue &arguments,
                          MethodResultPtr result);
  void GetInstalledApplicationsInfo(MethodResultPtr result);
  void ApplicationIsRunning(const flutter::EncodableValue &arguments,
                            MethodResultPtr result);
  void SetupChannels(flutter::PluginRegistrar *registrar);

  flutter::EncodableList applications_;
  bool has_registered_event_;
  int registered_cnt_;
};

#endif
