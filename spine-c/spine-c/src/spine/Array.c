/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated January 1, 2020. Replaces all prior versions.
 *
 * Copyright (c) 2013-2020, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <spine/Array.h>
#include <spine/extension.h>

//_SP_ARRAY_IMPLEMENT_TYPE(spFloatArray, float)


spFloatArray* spFloatArray_create(int initialCapacity) {
    spFloatArray* array = CALLOC(spFloatArray, 1);
    array->size = 0;
    array->capacity = initialCapacity;
    array->items = CALLOC(float, initialCapacity);
    return array;
}
    void spFloatArray_dispose(spFloatArray* self) {
        FREE(self->items);
        FREE(self);
    }
    void spFloatArray_clear(spFloatArray* self) {
        self->size = 0;
    }
    spFloatArray* spFloatArray_setSize(spFloatArray* self, int newSize) {
        self->size = newSize;
        if (self->capacity < newSize) {
            self->capacity = MAX(8, (int)(self->size * 1.75f));
            self->items = REALLOC(self->items, float, self->capacity);
        }
        return self;
    }
    void spFloatArray_ensureCapacity(spFloatArray* self, int newCapacity) {
        if (self->capacity >= newCapacity) return;
        self->capacity = newCapacity;
        self->items = REALLOC(self->items, float, self->capacity);
    }
    void spFloatArray_add(spFloatArray* self, float value) {
        if (self->size == self->capacity) {
            self->capacity = MAX(8, (int)(self->size * 1.75f));
            self->items = REALLOC(self->items, float, self->capacity);
        }
        self->items[self->size++] = value;
        if(self->size >= 7310)
        {
            int ss = 0;
        }
    }
    void spFloatArray_addAll(spFloatArray* self, spFloatArray* other) {
        int i = 0;
        for (; i < other->size; i++) {
            spFloatArray_add(self, other->items[i]);
        }
    }
    void spFloatArray_addAllValues(spFloatArray* self, float* values, int offset, int count) {
        int i = offset, n = offset + count;
        for (; i < n; i++) {
            spFloatArray_add(self, values[i]);
        }
    }
    void spFloatArray_removeAt(spFloatArray* self, int index) {
        self->size--;
        memmove(self->items + index, self->items + index + 1, sizeof(float) * (self->size - index));
    }
    int spFloatArray_contains(spFloatArray* self, float value) {
        float* items = self->items;
        int i, n;
        for (i = 0, n = self->size; i < n; i++) {
            if (items[i] == value) return -1;
        }
        return 0;
    }
    float spFloatArray_pop(spFloatArray* self) {
        float item = self->items[--self->size];
        return item;
    }
    float spFloatArray_peek(spFloatArray* self) {
        return self->items[self->size - 1];
    }


_SP_ARRAY_IMPLEMENT_TYPE(spIntArray, int)
_SP_ARRAY_IMPLEMENT_TYPE(spShortArray, short)
_SP_ARRAY_IMPLEMENT_TYPE(spUnsignedShortArray, unsigned short)
_SP_ARRAY_IMPLEMENT_TYPE(spArrayFloatArray, spFloatArray*)
_SP_ARRAY_IMPLEMENT_TYPE(spArrayShortArray, spShortArray*)
