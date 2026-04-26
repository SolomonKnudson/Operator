#ifndef OPERATOR_MACROS_HPP
#define OPERATOR_MACROS_HPP

#if defined(__cpp_concepts)
#define OPERATOR_CREATE_REQUIRES(...) requires __VA_ARGS__
#define OPERATOR_CREATE_TRAILING_RETURN(...)

#define OPERATOR_CREATE_HAS_METHOD_CONCEPT(operation, method)                  \
  template <typename Type, typename... Args>                                   \
  concept Has##operation = OPERATOR_CREATE_REQUIRES(                           \
      (Type type, Args&&... args) { type.method(args...); });
#else
#define OPERATOR_CREATE_REQUIRES(...)
#define OPERATOR_CREATE_TRAILING_RETURN(...) ->__VA_ARGS__
#endif

#define OPERATOR_CREATE_TAG(name)                                              \
  struct name                                                                  \
  {                                                                            \
  };

#endif // OPERATOR_MACROS_HPP
