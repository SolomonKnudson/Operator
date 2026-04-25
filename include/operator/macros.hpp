#ifndef OPERATOR_MACROS_HPP
#define OPERATOR_MACROS_HPP

#if defined(__cpp_concepts)
#define OPERATOR_CONCEPT(...) requires __VA_ARGS__
#define OPERATOR_TRAILING_RETURN(...)
#else
#define OPERATOR_CONCEPT(...)
#define OPERATOR_TRAILING_RETURN(...) ->__VA_ARGS__
#endif

#define OPERATOR_CREATE_TAG(name)                                              \
  struct name                                                                  \
  {                                                                            \
  };

#define OPERATOR_CREATE_HAS_INSERTION_OP_CONCEPT(insertion_name,               \
                                                 insertion_function)           \
  template <typename Container, typename... Args>                              \
  concept Has##insertion_name =                                                \
      requires(Container container, Args&&... args) {                          \
        container.insertion_function(args...);                                 \
      };
#endif // OPERATOR_MACROS_HPP
