#ifndef MODULE_H
#define MODULE_H

#include "../../common/keys.h"
#include "../../common/types.h"
#include "../../decoder/Event.h"
#include "../Rule.h"

namespace absolem {

    class Interpreter;

    class Module {
        public:
        static const Byte defaultPriority;

        Module(String n) : name(n) {}
        String getName();

        virtual bool onBeforeEnqueue(List<Event>& e);
        virtual Byte onBeforeEnqueuePriority();

        virtual bool onAfterEnqueue(List<Event>& e);
        virtual Byte onAfterEnqueuePriority();

        virtual bool onDirectSearch(Key k, List<Rule>& candidates);
        virtual Byte onDirectSearchPriority();

        virtual bool onMapKey(VirtualKey& k);
        virtual Byte onMapKeyPriority();

        virtual bool onVirtualSearch(VirtualKey k, List<Rule>& candidates);
        virtual Byte onVirtualSearchPriority();

        virtual bool onAfterTick();
        virtual Byte onAfterTickPriority();

        protected:
        String name;
        Interpreter* interpreter;

        friend class Interpreter;
    };

} // namespace absolem

#endif