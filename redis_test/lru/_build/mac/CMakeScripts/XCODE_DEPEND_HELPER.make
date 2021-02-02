# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.LRU.Debug:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/Debug/LRU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/Debug/LRU


PostBuild.LRU.Release:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/Release/LRU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/Release/LRU


PostBuild.LRU.MinSizeRel:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/MinSizeRel/LRU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/MinSizeRel/LRU


PostBuild.LRU.RelWithDebInfo:
/Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/RelWithDebInfo/LRU:
	/bin/rm -f /Users/yangsen/work/redis/redis-6.0.9/redis_test/adlist/_build/mac/RelWithDebInfo/LRU




# For each target create a dummy ruleso the target does not have to exist
