#-------------------------------------------------
#
# Project created by QtCreator 2017-02-22T21:08:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cppjieba-demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    include/deps/gtest/src/gtest-all.cc \
    include/deps/gtest/src/gtest-death-test.cc \
    include/deps/gtest/src/gtest-filepath.cc \
    include/deps/gtest/src/gtest-port.cc \
    include/deps/gtest/src/gtest-printers.cc \
    include/deps/gtest/src/gtest-test-part.cc \
    include/deps/gtest/src/gtest-typed-test.cc \
    include/deps/gtest/src/gtest.cc \
    include/deps/gtest/src/gtest_main.cc

HEADERS  += mainwindow.h \
    include/cppjieba/DictTrie.hpp \
    include/cppjieba/FullSegment.hpp \
    include/cppjieba/HMMModel.hpp \
    include/cppjieba/HMMSegment.hpp \
    include/cppjieba/Jieba.hpp \
    include/cppjieba/KeywordExtractor.hpp \
    include/cppjieba/MixSegment.hpp \
    include/cppjieba/MPSegment.hpp \
    include/cppjieba/PosTagger.hpp \
    include/cppjieba/PreFilter.hpp \
    include/cppjieba/QuerySegment.hpp \
    include/cppjieba/SegmentBase.hpp \
    include/cppjieba/SegmentTagged.hpp \
    include/cppjieba/TextRankExtractor.hpp \
    include/cppjieba/Trie.hpp \
    include/cppjieba/Unicode.hpp \
    include/deps/gtest/include/gtest/internal/gtest-death-test-internal.h \
    include/deps/gtest/include/gtest/internal/gtest-filepath.h \
    include/deps/gtest/include/gtest/internal/gtest-internal.h \
    include/deps/gtest/include/gtest/internal/gtest-linked_ptr.h \
    include/deps/gtest/include/gtest/internal/gtest-param-util-generated.h \
    include/deps/gtest/include/gtest/internal/gtest-param-util.h \
    include/deps/gtest/include/gtest/internal/gtest-port.h \
    include/deps/gtest/include/gtest/internal/gtest-string.h \
    include/deps/gtest/include/gtest/internal/gtest-tuple.h \
    include/deps/gtest/include/gtest/internal/gtest-tuple.h.pump \
    include/deps/gtest/include/gtest/internal/gtest-type-util.h \
    include/deps/gtest/include/gtest/gtest-death-test.h \
    include/deps/gtest/include/gtest/gtest-message.h \
    include/deps/gtest/include/gtest/gtest-param-test.h \
    include/deps/gtest/include/gtest/gtest-param-test.h.pump \
    include/deps/gtest/include/gtest/gtest-printers.h \
    include/deps/gtest/include/gtest/gtest-spi.h \
    include/deps/gtest/include/gtest/gtest-test-part.h \
    include/deps/gtest/include/gtest/gtest-typed-test.h \
    include/deps/gtest/include/gtest/gtest.h \
    include/deps/gtest/include/gtest/gtest_pred_impl.h \
    include/deps/gtest/include/gtest/gtest_prod.h \
    include/deps/gtest/src/gtest-internal-inl.h \
    include/deps/limonp/ArgvContext.hpp \
    include/deps/limonp/BlockingQueue.hpp \
    include/deps/limonp/BoundedBlockingQueue.hpp \
    include/deps/limonp/BoundedQueue.hpp \
    include/deps/limonp/Closure.hpp \
    include/deps/limonp/Colors.hpp \
    include/deps/limonp/Condition.hpp \
    include/deps/limonp/Config.hpp \
    include/deps/limonp/FileLock.hpp \
    include/deps/limonp/ForcePublic.hpp \
    include/deps/limonp/LocalVector.hpp \
    include/deps/limonp/Logging.hpp \
    include/deps/limonp/Md5.hpp \
    include/deps/limonp/MutexLock.hpp \
    include/deps/limonp/NonCopyable.hpp \
    include/deps/limonp/StdExtension.hpp \
    include/deps/limonp/StringUtil.hpp \
    include/deps/limonp/Thread.hpp \
    include/deps/limonp/ThreadPool.hpp

FORMS    += mainwindow.ui

DISTFILES += \
    include/deps/gtest/include/gtest/internal/gtest-param-util-generated.h.pump \
    include/deps/gtest/include/gtest/internal/gtest-type-util.h.pump \
    include/deps/gtest/src/.deps/.dirstamp \
    include/deps/gtest/src/.deps/gtest-all.Plo \
    include/deps/gtest/src/.deps/gtest_main.Plo \
    include/deps/gtest/src/.dirstamp \
    include/deps/gtest/CMakeLists.txt \
    include/deps/CMakeLists.txt
