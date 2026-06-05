#ifndef OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
#define OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
#include <operator/builtin.hpp>
#include <operator/impl.hpp>
#include <operator/util.hpp>

// 3rd Party
// STL
#include <iostream>

namespace Operator
{
  template <> struct Impl<builtin::iostream>
  {
    template <typename IStream, typename LValue>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasStdStreamInsertion<IStream, LValue>)
    static OPERATOR_AUTO_RETURN invoke(IStream& in_stream, LValue&& l_value)
        OPERATOR_CREATE_TRAILING_RETURN(
            decltype(in_stream >> util::deref(std::forward<LValue>(l_value)),
                     void()))
    {
      in_stream >> util::deref(std::forward<LValue>(l_value));
    }

    template <typename OStream, typename... OStreamArgs>
    OPERATOR_CREATE_REQUIRES(
        internal::concepts::HasStdStreamOutsertion<OStream, OStreamArgs...>)
    static OPERATOR_AUTO_RETURN
        invoke(OStream& out_stream, OStreamArgs&&... args)
            OPERATOR_CREATE_TRAILING_RETURN(
                decltype(((out_stream << std::forward<OStreamArgs>(args)), ...),
                         void()))
    {
      static_assert(sizeof...(OStreamArgs) > 0,
                    "Operator::Impl<builtin::iostream>(args...): "
                    "ostream must be called with at least one value!");

      ((out_stream << args), ...);
    }
  };

  template <> struct Impl<builtin::cin>
  {
    template <typename LValue>
    static decltype(auto)
    invoke(LValue&& l_value)
    {
      return Impl<builtin::iostream>::invoke(std::cin,
                                             std::forward<LValue>(l_value));
    }
  };

  template <> struct Impl<builtin::wcin>
  {
    template <typename LValue>
    static decltype(auto)
    invoke(LValue&& l_value)
    {
      return Impl<builtin::iostream>::invoke(std::wcin,
                                             std::forward<LValue>(l_value));
    }
  };

  template <> struct Impl<builtin::cout>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::cout,
                                             std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::wcout>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::wcout,
                                             std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::cerr>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::cerr,
                                             std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::wcerr>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::wcerr,
                                             std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::clog>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::clog,
                                             std::forward<Args>(args)...);
    }
  };

  template <> struct Impl<builtin::wclog>
  {
    template <typename... Args>
    static decltype(auto)
    invoke(Args&&... args)
    {
      return Impl<builtin::iostream>::invoke(std::wclog,
                                             std::forward<Args>(args)...);
    }
  };
} // namespace Operator
#endif // OPERATOR_INTERNAL_IOSTREAM_IMPLS_HPP
