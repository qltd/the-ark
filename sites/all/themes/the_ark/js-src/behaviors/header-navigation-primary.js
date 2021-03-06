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
        body[method]('document-modal-mobile');
        toggle[method]('active');
        wrapper[method]('menu-flyout-visible');
        switch (method) {
          case 'addClass':
            toggle.off('tap');

            $(document).on('touchmove', function (e) {
              e.preventDefault();
            });
            navigation.on('touchmove', function (e) {
              e.stopPropagation();
            });
            buttonClose.on('tap', function () {
              toggleClasses('removeClass');
            });

            break;
          case 'removeClass':
            $(document).off('touchmove');
            navigation.off('touchmove');
            buttonClose.off('tap');

            defaultListeners();
            break;
        }
      };

      var defaultListeners = function () {
        toggle.on('tap', function () {
          toggleClasses('addClass');
        });
      };
      defaultListeners();

    }
  };
})(jQuery);
