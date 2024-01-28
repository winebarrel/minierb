/*
** mrb_minierb.c - Minierb class
**
** Copyright (c) winebarrel 2024
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_minierb.h"

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  mrb_int len;
} mrb_minierb_data;

static const struct mrb_data_type mrb_minierb_data_type = {
  "mrb_minierb_data", mrb_free,
};

static mrb_value mrb_minierb_init(mrb_state *mrb, mrb_value self)
{
  mrb_minierb_data *data;
  char *str;
  mrb_int len;

  data = (mrb_minierb_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_minierb_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_minierb_data *)mrb_malloc(mrb, sizeof(mrb_minierb_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_minierb_hello(mrb_state *mrb, mrb_value self)
{
  mrb_minierb_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_minierb_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_minierb_gem_init(mrb_state *mrb)
{
  struct RClass *minierb;
  minierb = mrb_define_class(mrb, "Minierb", mrb->object_class);
  mrb_define_method(mrb, minierb, "initialize", mrb_minierb_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, minierb, "hello", mrb_minierb_hello, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, minierb, "hi", mrb_minierb_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_minierb_gem_final(mrb_state *mrb)
{
}

