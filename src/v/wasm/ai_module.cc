/*
 * Copyright 2024 Redpanda Data, Inc.
 *
 * Licensed as a Redpanda Enterprise file under the Redpanda Community
 * License (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 * https://github.com/redpanda-data/redpanda/blob/master/licenses/rcl.md
 */
#include "ai_module.h"

namespace wasm {

ss::future<int32_t>
ai_module::generate_text(ss::sstring, int32_t, ffi::array<uint8_t>) {
    co_return -1;
    // auto result = co_await _service->generate_text(
    //   std::move(prompt), {.max_tokens = max_tokens});

    // size_t copy_n = std::min(generated_output.size(), result.size());
    // for (size_t i = 0; i < copy_n; ++i) {
    //     generated_output[i] = uint8_t(result[i]);
    // }
    // co_return int32_t(result.size());
}

ss::future<int32_t> ai_module::compute_embeddings(
  ss::sstring text, ffi::array<float> generated_output) {
    auto result = co_await _service->compute_embeddings(std::move(text));

    size_t copy_n = std::min(generated_output.size(), result.size());
    for (size_t i = 0; i < copy_n; ++i) {
        generated_output[i] = result[i];
    }
    co_return int32_t(result.size());
}

ai_module::ai_module(ai::service* service)
  : _service(service) {}
} // namespace wasm
