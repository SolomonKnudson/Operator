#ifndef INSERTER_MACROS
#define INSERTER_MACROS

#if defined(__cpp_concepts)
#define INSERTER_CONCEPT(...) requires __VA_ARGS__
#define INSERTER_TRAILING_RETURN(...)
#else
#define INSERTER_CONCEPT(...)
#define INSERTER_TRAILING_RETURN(...) ->__VA_ARGS__
#endif

#define INSERTER_CREATE_TAG(name)                                              \
  struct name                                                                  \
  {                                                                            \
  };

#define INSERTER_CREATE_HAS_INSERTION_OP_CONCEPT(insertion_name,               \
                                                 insertion_function)           \
  template <typename Container, typename... Args>                              \
  concept Has##insertion_name =                                                \
      requires(Container container, Args&&... args) {                          \
        container.insertion_function(args...);                                 \
      };
#endif
