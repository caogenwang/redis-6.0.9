# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.LFU.Debug:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/Debug/LFU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/Debug/LFU


PostBuild.LFU.Release:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/Release/LFU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/Release/LFU


PostBuild.LFU.MinSizeRel:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/MinSizeRel/LFU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/MinSizeRel/LFU


PostBuild.LFU.RelWithDebInfo:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/RelWithDebInfo/LFU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/lfu/_build/mac/RelWithDebInfo/LFU




# For each target create a dummy ruleso the target does not have to exist
