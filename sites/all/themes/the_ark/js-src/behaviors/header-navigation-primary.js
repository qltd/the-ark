(function ($) {
  Drupal.behaviors.theArkHeaderNavigationPrimary = {
    attach: function () {
      var body = $('body')
        , wrapper = $('.menu-primary-wrapper')
        , navigation = $('.menu-primary-wrapper > .menu')
        , toggle = $('.header-navigation-primary .block__title')
        , buttonClose = $('.menu-primary-close');
      if (wrapper.length === 0 || navigation.length === 0) return;

      var toggleClasses = function (method) {
        body[method]('document-no-scroll');
        toggle[method]('active');
        wrapper[method]('menu-flyout-visible');
        switch (method) {
          case 'addClass':
            $(document).bind('touchmove', function (e) {
              e.preventDefault();
            });
            break;
          case 'removeClass':
            $(document).off('touchmove');
            break;
        }
      };

      navigation.bind('touchmove', function (e) {
        e.stopPropagation();
      });

      body.bind('swiperight', function (e) {
        e.preventDefault();
        toggleClasses('addClass');
      });
      navigation.bind('swipeleft', function (e) {
        e.preventDefault();
        toggleClasses('removeClass');
      });
      toggle.bind('tap', function (e) {
        e.preventDefault();
        toggleClasses('addClass');
      });
      buttonClose.bind('tap', function (e) {
        e.preventDefault();
        toggleClasses('removeClass');
      });
    }
  };
})(jQuery);
