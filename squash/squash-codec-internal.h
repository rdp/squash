/* Copyright (c) 2013-2016 The Squash Authors
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *   Evan Nemerson <evan@nemerson.com>
 */
/* IWYU pragma: private, include "squash-internal.h" */

#ifndef SQUASH_CODEC_INTERNAL_H
#define SQUASH_CODEC_INTERNAL_H

#if !defined (SQUASH_COMPILATION)
#error "This is internal API; you cannot use it."
#endif

HEDLEY_BEGIN_C_DECLS

SQUASH_INTERNAL
SquashCodec*            squash_codec_new                     (SquashPlugin* plugin, const char* name);
HEDLEY_NON_NULL(1) SQUASH_INTERNAL
void                    squash_codec_set_extension           (SquashCodec* codec, const char* extension);
HEDLEY_NON_NULL(1) SQUASH_INTERNAL
void                    squash_codec_set_priority            (SquashCodec* codec, unsigned int priority);
HEDLEY_NON_NULL(1, 2) SQUASH_INTERNAL
int                     squash_codec_compare                 (SquashCodec* a, SquashCodec* b);
HEDLEY_NON_NULL(1, 2) SQUASH_INTERNAL
int                     squash_codec_extension_compare       (SquashCodec* a, SquashCodec* b);
HEDLEY_NON_NULL(1) SQUASH_INTERNAL
SquashCodecImpl*        squash_codec_get_impl                (SquashCodec* codec);
HEDLEY_NON_NULL(1, 2, 4) SQUASH_INTERNAL
SquashStatus            squash_codec_decompress_to_buffer    (SquashCodec* codec,
                                                              SquashBuffer* decompressed,
                                                              size_t compressed_size,
                                                              uint8_t compressed[HEDLEY_ARRAY_PARAM(compressed_size)],
                                                              SquashOptions* options);

SQUASH_TREE_PROTOTYPES(SquashCodec_, tree)
SQUASH_TREE_DEFINE(SquashCodec_, tree)

HEDLEY_END_C_DECLS

#endif /* SQUASH_CODEC_INTERNAL_H */
